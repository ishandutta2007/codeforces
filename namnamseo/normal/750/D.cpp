#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
typedef pair<int,int> pp;

typedef set<pp> pts;

int N;
int t[40];

int dx[8]={0, 1, 1, 1, 0, -1, -1, -1};
int dy[8]={1, 1, 0, -1, -1, -1, 0, 1};

int sint[4]={0,1,0,-1};

pts getPicture(int n, int dir){
    pts ret;
    int tn = t[n];
    int lp=0, rp=0;
    for(int i=0; i<tn; ++i) ret.insert({lp=i*dx[dir], rp=i*dy[dir]});
    int nd = (dir+1)%8;

    if(n < N){
        auto tmp = getPicture(n+1, nd);
        for(auto p : tmp){
            pp np = {dx[nd] + p.first, dy[nd] + p.second};
            ret.insert({lp+np.first, rp+np.second});
            np = {
                sint[(dir+3)&3]*np.first + sint[(dir+0)&3]*np.second,
                sint[(dir+0)&3]*np.first + sint[(dir+1)&3]*np.second
            };
            ret.insert({lp+np.first, rp+np.second});
        }
    }
    return ret;
}

int main()
{
    read(N); for(int i=1; i<=N; ++i) read(t[i]);
    auto tmp = getPicture(1, 0);
    printf("%d\n", int(tmp.size()));
    return 0;
}