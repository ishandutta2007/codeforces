#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int n,s;

struct Node{//   
    LL tag;
    std::map<int,LL> mp;//  i  set 
    std::multiset<LL> S;
    Node(LL tag=0) : tag(tag) {}
    inline void update(int p,LL d){
        if(p == s) return;
        if(mp.count(p)) S.erase(S.find(mp[p]));
        mp[p] = d-tag;
        S.insert(mp[p]);
    }

    inline LL get(int p){
        if(!mp.count(p)) return 1e18;
        return mp[p]+tag;
    }

    inline void upmin(int p,LL d){
        if(p == s) return;
        if(get(p) > d) update(p,d);
    }

    inline LL query(){
        return *S.begin() + tag;
    }
};

std::vector<Node> st;
std::vector<int> oo;

int main(){
    scanf("%d%d",&n,&s);
    Node v;v.update(0,0);
    st.pb(v);oo.pb(-114514);
    FOR(i,1,n){
        char opt[12];scanf("%s",opt);
        if(opt[0] == 's'){
            int x,y;scanf("%d%d",&x,&y);
            if(st.back().mp.empty()) continue;
            LL c = st.back().query();
            st.back().tag += y;st.back().upmin(x,c);
        }
        if(opt[0] == 'i'){
            int x;scanf("%d",&x);
            LL c = st.back().get(x);
            Node v;if(c != 1e18) v.update(x,c);
            st.pb(v);oo.pb(x);
        }
        if(opt[0] == 'e'){
            int tp = (int)st.size()-1,o = oo.back();bool flag = 1;
            if(st[tp].mp.size() > st[tp-1].mp.size()) std::swap(st[tp],st[tp-1]),flag = 0;
            for(auto x:st[tp].mp){
                if(x.fi != o) st[tp-1].upmin(x.fi,x.se+st[tp].tag);
                else{
                    if(flag) st[tp-1].update(x.fi,x.se+st[tp].tag);
                }
            }
            st.pop_back();oo.pop_back();
        }
//        if(i == 8){
//            for(auto x:st.back().mp) DEBUG(x.fi),DEBUG(st.back().get(x.fi));
//        }
    }
    printf("%lld\n",st[0].query());
    return 0;
}