#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200200
#define debug 
#define mod 998244353
#define pii pair<int,int>
#define d2 

set<int> has[4*maxn];
set<int> all[4*maxn];
ll T[4*maxn];
ll lazy_add[4*maxn];
ll lazy_mul[4*maxn];

inline void refresh(int ini,int fim,int p){
    T[p] *= lazy_mul[p];
    T[p] += lazy_add[p] * (fim-ini+1);
    T[p] %= mod;
    if(ini != fim){
        for(int f=2*p;f<=2*p+1;f++){
            lazy_mul[f] *= lazy_mul[p];
            lazy_add[f] *= lazy_mul[p];
            lazy_add[f] += lazy_add[p];
            lazy_mul[f] %= mod;
            lazy_add[f] %= mod;
        }
    }
    lazy_mul[p] = 1;
    lazy_add[p] = 0;
}

inline ll get(int ini,int fim,int p,int l,int r){
    
    refresh(ini,fim,p);
    
    if(l > fim ||r < ini)
        return 0;
        
    if(ini >= l && fim <= r)
        return T[p];
        
    int m = (ini+fim)/2;
    ll ret = get(ini,m,2*p,l,r) + get(m+1,fim,2*p+1,l,r);
   if(ret > mod)
    ret -= mod;
    return ret;
    
}

inline int add(int ini,int fim,int p,int l,int r,int val,int tipo,int c=1){
     if(c)d2("add %d %d %d tipo %d\n",l,r,val,tipo);
     if(l > r) return -1;
    refresh(ini,fim,p);
    
  //  if(fall == 0 && all[p].find(val) != all[p].end())
    //    fall = 1;
        
    if(l > fim || r < ini)
        return 0;
    
    if(ini >= l && fim <= r){
        if(tipo == 1)
            lazy_add[p] = 1;
        else
            lazy_mul[p] = 2;
        refresh(ini,fim,p);
    //    has[p].insert(val);
     //   all[p].insert(val);
        return 1;
    }
    
    int m = (ini+fim)/2;
    int a = add(ini,m,2*p,l,r,val,tipo,0);
    int b = add(m+1,fim,2*p+1,l,r,val,tipo,0);
   // has[p].insert(val);
  //  if(a&b)
    //    all[p].insert(val);
    T[p] = (T[2*p] + T[2*p+1]);
    if(T[p] > mod)
        T[p] -= mod;
    return a&b;
}

char ch;
void read(int &x){
    x = 0;
    while((ch=getchar()) >= '0')
        x = 10*x+ch-'0';
}

set<pii> S[maxn];

main(){
    int n,q;
  
    read(n);
    read(q);
    for(int i=0;i<4*n;i++)
        lazy_mul[i] = 1;
    for(int i=0;i<q;i++){
        int t,l,r,val;
        read(t);
        read(l);
        read(r);
        l--, r--;
        if(t == 1){
            read(val);
            int last = l;
            set<pii> :: iterator it = S[val].lower_bound(pii(l,-1));
            for(set<pii> :: iterator ii = S[val].begin(); ii != S[val].end();ii++)
                d2(" (%d;%d) ",ii->first,ii->second);
            d2("\n\n");
            int exc = -1;
            if(it != S[val].begin()) it--;
           if(it != S[val].end()) debug("it %d %d\n",it->first,it->second);
            if(it == S[val].end() || it->first > r)
                add(0,n-1,1,l,r,val,1);
                
            else {
                int upto = l;
                while(it != S[val].end() && it->first <= r){
                    
                    if(it->second < l){
                        it++;
                        continue;
                    }
                    
                    if(it->first > upto)
                        add(0,n-1,1,upto,it->first-1,val,1);
                        
                    d2("oi %d %d\n",it->first,it->second);
                    add(0,n-1,1,max(upto,it->first),min(it->second,r),val,2);
                    upto = max(upto,1+it->second);
                    set<pii> :: iterator it2 = it;
                    it++;
                    exc = it2->second;
                    if(it2->first < l){
                        int aa = it2->first, bb = min(l-1,it2->second);
                        S[val].erase(it2);
                        S[val].insert(pii(aa,bb));
                        
                    }
                   else  S[val].erase(it2);
                    
                }
                if(upto <= r)
                    add(0,n-1,1,max(upto,l),r,val,1);
                
            }    S[val].insert(pii(l,r));d2("ok\n");
            if(exc > r)
                S[val].insert(pii(r+1,exc));
            //add(0,n-1,1,l,r,val);
        }
        else {
            ll ans = get(0,n-1,1,l,r);
            printf("%lld\n",ans);
        }
    }
    
}