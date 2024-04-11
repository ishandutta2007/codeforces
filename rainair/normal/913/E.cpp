#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

struct Node{// S:  i: &|
    std::string s;
    int S,i;
    Node(std::string s=std::string(""),int S=0,int i=0) : s(s),S(S),i(i) {}

    inline bool operator < (const Node &t) const {
        if(s.size() != t.s.size()) return s.size() > t.s.size();
        return s > t.s;
    }
};
std::string f[(1<<8)+5][2];
std::priority_queue<Node> q;

inline void upd(int S,int i,std::string str){
    if(!(Node(str)<Node(f[S][i]))){
        f[S][i] = str;
        q.push(Node(f[S][i],S,i));
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    FOR(S,0,255) FOR(i,0,1) FOR(j,0,100) f[S][i] += 'z'+1;
    upd((1<<4)|(1<<5)|(1<<6)|(1<<7),0,"x");
    upd((1<<2)|(1<<3)|(1<<6)|(1<<7),0,"y");
    upd((1<<1)|(1<<3)|(1<<5)|(1<<7),0,"z");
    upd(255^((1<<4)|(1<<5)|(1<<6)|(1<<7)),0,"!x");
    upd(255^((1<<2)|(1<<3)|(1<<6)|(1<<7)),0,"!y");
    upd(255^((1<<1)|(1<<3)|(1<<5)|(1<<7)),0,"!z");
    while(!q.empty()){
        Node v = q.top();q.pop();
        if(v.s != f[v.S][v.i]) continue;
        upd(255^v.S,0,std::string("!(")+v.s+std::string(")"));
        FOR(S,0,255){// |
            FOR(i,0,1){
                if(f[S][i][0]=='z'+1) continue;
                upd(S|v.S,1,v.s+std::string("|")+f[S][i]);
                upd(S|v.S,1,f[S][i]+std::string("|")+v.s);
            }
        }
        FOR(S,0,255){
            FOR(i,0,1){
                if(f[S][i][0] == 'z'+1) continue;
                std::string s1=v.s,s2=f[S][i];
                if(v.i) s1 = std::string("(")+s1+std::string(")");
                if(i) s2 = std::string("(")+s2+std::string(")");
                upd(S&v.S,0,s1+std::string("&")+s2);
                upd(S&v.S,0,s2+std::string("&")+s1);
            }
        }
    }
    int n;std::cin >> n;
    while(n--){
        std::string str;std::cin >> str;
        int S = 0;FOR(i,0,7) S |= (str[i]-'0')<<i;
        std::cout << std::max(Node(f[S][0]),Node(f[S][1])).s << '\n';
    }
    return 0;
}