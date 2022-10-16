#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef pair < int,int> pii;
typedef pair < int,pii> st;
typedef pair < pii,int> st2;

const int N = 5055;
const int LOG = 11;
const int MSK = (1 << LOG) + 10;

pii dp2[N][MSK];
int rek[N][MSK];
int lg,n;
char s[N],miin[N];
vector < st > v;
vector < st2 > v2;

int getlen(int x,int msk){
    int ret = x + 1;
    for(int i = 0;i<lg;i++){
        if(msk & (1 << i))
            ret -= (1 << i);
    }
    return ret;
}

void solve(){
    char ez = s[0];
    for(int i = 0;i<n;i++){
        if(s[i] < ez) ez = s[i];
        miin[i] = ez;
        for(int j = 0;j<(1 << lg);j++){
            if(i + 1 - j >= 1 && i + 1 - j <= n + 1 - (1 << lg))
                v.push_back(MP(i + 1 - j,MP(i,j)));
            if(i + 1 - j == 0){
                dp2[i][j] = MP(0,0);
                rek[i][j] = 0;
            }
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
        int r = i;
        while(r < v.size() && v[r].X == v[i].X) r++;
        for(int j = i;j<r;j++){
            int x = v[j].Y.X;
            int msk = v[j].Y.Y;
            pii sol = MP((x > 0) ? dp2[x - 1][msk].X : 0,s[x]);
            rek[x][msk] = -1;
            for(int k = 0;k<lg;k++){
                if(!(msk&(1<<k))) continue;
                if(x - (1 << k) >= 0 && dp2[x - (1<<k)][msk - (1<<k)] < sol){
                    sol = dp2[x - (1<<k)][msk - (1<<k)];
                    rek[x][msk] = k;
                }
                if(x - (1 << k) <  0){
                    sol = MP(0, 0);
                    rek[x][msk] = k;
                }
            }
            dp2[x][msk] = sol;
            v2.push_back(MP(sol,j));
        }
        sort(v2.begin(),v2.end());
        int j = 0;
        for(int i = 0;i<v2.size();i++){
            if(i > 0 && v2[i].X != v2[i - 1].X) j++;
            dp2[v[v2[i].Y].Y.X][v[v2[i].Y].Y.Y].X = j;
        }
        v2.clear();
        i = r - 1;
    }
}

int main(){
    scanf("%s",s);
    n = strlen(s);
    while((1 << lg) <= n) lg++;
    lg--;
    solve();
    int x = n - 1,msk = (1 << lg) - 1;
    string sol = "";
    while(x >= 0){
        if(rek[x][msk] == -1){
            sol.push_back(s[x]);
            x--;continue;
        }
        else{
            int rm = (1 << rek[x][msk]);
            x -= rm;
            msk -= rm;
        }
    }
    reverse(sol.begin(),sol.end());
    cout << sol << endl;
}