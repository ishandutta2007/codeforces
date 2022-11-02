#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int n,m;
std::vector<std::vector<int> > A;

int main(){
    scanf("%d%d",&n,&m);
    A.resize(n+1);FOR(i,1,n) A[i].resize(m+1);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&A[i][j]);
    FOR(i,2,n){
        std::vector<int> vec;
        FOR(j,1,m) if(A[1][j]^A[i][j]) vec.pb(j);
        if(SZ(vec) > 4){
            puts("No");
            return 0;
        }
        if(SZ(vec) <= 2) continue;
        if(SZ(vec) == 3){
            FOR(x,0,2){
                FOR(y,0,2){
                    if(x == y) continue;
                    std::vector<int> ans = A[1];
                    ans[vec[x]] = A[1][vec[x]];
                    ans[vec[y]] = A[i][vec[y]];
                    auto chk = [&](int x){
                        int las = -1;
                        FOR(i,1,n){
                            int c = 0;
                            FOR(j,1,m) c += (j != x && ans[j] != A[i][j]);
                            if(c > 2) return false;
                            if(c < 2) continue;
                            if(las != -1 && las != A[i][x]) return false;
                            las = A[i][x];
                        }
                        if(las != -1) ans[x] = las;
                        return true;
                    };
                    if(chk(vec[3-x-y])){
                        puts("Yes");
                        FOR(i,1,m) printf("%d%c",ans[i]," \n"[i==m]);
                        return 0;
                    }
                }
            }
        }
        if(SZ(vec) == 4){
            FOR(S,0,(1<<SZ(vec))-1){
                if(__builtin_popcount(S) != 2) continue;
                int p = __builtin_ctz(S),q = __builtin_ctz(S^(1<<p));
                p = vec[p];q = vec[q];
                for(auto x:{1,i}){
                    std::vector<int> ans = A[1];
                    ans[p] = A[x][p];
                    ans[q] = A[x][q];
                    auto chk = [&](){
                        FOR(i,1,n){
                            int c = 0;
                            FOR(j,1,m){
                                c += ans[j] != A[i][j];
                            }
                            if(c > 2) return false;
                        }
                        return true;
                    };
                    if(chk()){
                        puts("Yes");
                        FOR(i,1,m) printf("%d%c",ans[i]," \n"[i==m]);
                        return 0;
                    }
                }
            }
        }
        puts("No");
        return 0;
    }
    puts("Yes");
    FOR(i,1,m) printf("%d%c",A[1][i]," \n"[i==m]);
    return 0;
}