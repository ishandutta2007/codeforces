#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define pii pair<int,int>
#define ll long long
using namespace std;

int v[maxn];
ll on[maxn];

void upd(ll *T,int idx,int val){
    idx++;
    while(idx < maxn){
        T[idx] += val;
        idx += idx&-idx;
    }
}

int sum(ll *T,int idx){
    idx++;
    ll r = 0;
    while(idx){
        r += T[idx];
        idx -= idx&-idx;
    }
    return r;
}

ll ss(ll a,ll b){
    ll r = (b*(b+1))/2;
    a--;
    r -= (a*(a+1))/2;
    return r;
}

ll ans1[maxn];
ll ans2[maxn];

int n;


int main() {
    
    scanf("%d",&n);
    
    vector<pii> a;
    
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
        a.pb(pii(v[i],i));
    }
    
    sort(a.begin(),a.end());
    
    ll s = 0;
    for(int i=0;i<n;i++){
        int pos = a[i].second;
        s += i-sum(on,pos);
        ans1[i] = s;
        upd(on,pos,1);
    }
    
    set<int> s1,s2;
    ll S1=0,S2=0;
    
    for(int i=0;i<n;i++){
        int pos = a[i].second;
        
        if(s2.size() == 0 || *s2.begin() > pos)
            s1.insert(pos), S1 += pos;
        else
            s2.insert(pos), S2 += pos;
        
        if(s1.size() < s2.size()){
            int u = *s2.begin();
            s2.erase(u);
            S2 -= u;
            S1 += u;
            s1.insert(u);
        }
        if(s1.size() > s2.size() + 1){
            int u = *--s1.end();
            s1.erase(u);
            S1 -= u;
            S2 += u;
            s2.insert(u);
        }
        int med;
        if(s1.size() >= s2.size()) med = (*--s1.end())+1;
        else med = *s2.begin();
        
      //  printf("i %d S1 %lld S2 %lld med %d\n",i,S1,S2,med);
        
        ans2[i] = S2 - ss(med,med+s2.size()-1);
        ans2[i] += ss(med-s1.size(),med-1) - S1;
        
        
    }
    
    for(int i=0;i<n;i++)
        printf("%lld ",ans1[i]+ans2[i]);
    printf("\n");
}