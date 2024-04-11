#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
const int MAXN = 1e6 + 5;
int n,r,c;
std::string str[MAXN];
int nxt[MAXN],len[MAXN],sum[MAXN];
int f[MAXN][21];

inline int calc(int i,int j){
    return sum[j]-sum[i-1]+(j-i);
}

int main(){
    std::cin >> n >> r >> c;
    FOR(i,1,n) std::cin >> str[i],len[i] = str[i].length(),sum[i] = sum[i-1]+len[i];
    int p = 1;
    FOR(i,1,n){
        if(len[i] > c){
            f[i][0] = 0;continue;
        }
        while(p < n && calc(i,p+1) <= c) p++;
        f[i][0] = p+1;
    }
    FOR(j,1,20) FOR(i,1,n) f[i][j] = f[f[i][j-1]][j-1];
    int al=1,ar=0;
    FOR(i,1,n){
        int t = r,pos = i;
        ROF(j,20,0){
            if(f[pos][j] && t >= (1<<j)){
                pos = f[pos][j];t -= (1<<j);
            }
        }
        if(pos-i > ar-al+1) al = i,ar = pos-1;
    }
    int cnt = 0,tot = 1;
    std::string out;
    FOR(i,al,ar){
        if(!out.empty() && out.length() + len[i] + 1 > c){
            std::cout << out << std::endl;
            out.clear();
        }
        if(out.empty()) out += str[i];
        else if(!out.empty() && out.length()+len[i]+1 <= c) out += " " + str[i];
    }
    if(!out.empty()) std::cout << out << std::endl;
    return 0;
}