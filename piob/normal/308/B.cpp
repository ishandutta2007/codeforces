#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <complex>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long LL;

int n, r, c, s, best;
vector<string> V;
char buff[5000010];
int len[1000010];
int jump[1000010][20];
int cjumps[1000010];
int res[1000010];

int main(){
    scanf("%d %d %d", &n, &r, &c);
    FWD(i,0,n){
        scanf("%s", buff);
        V.pb(string(buff));
        len[i] = strlen(buff)+1;
    }
    res[n] = 0;
    ++c;
    int k = 0;
    int sum = 0;
    FWD(i,0,n){
        while(k < i){
            sum += len[k];
            ++k;
        }
        while(k != n && sum + len[k] <= c){
            sum += len[k];
            ++k;
        }
        jump[i][0] = k;
        sum -= len[i];
    }
    jump[n][0] = n;
    BCK(i,n,-1)
        FWD(j,1,20){
            jump[i][j] = jump[jump[i][j-1]][j-1];
        }
    FWD(i,0,n){
        k = r;
        cjumps[i] = i;
        s = 0;
        while(k){
            if(k&(1<<s)){
                cjumps[i] = jump[cjumps[i]][s];
                k -= (1<<s);
            }
            ++s;
        }
    }
    best = 0;
    FWD(i,0,n){
        if(cjumps[i] - i > cjumps[best] - best)
            best = i;
    }
    bool first;
    while(best < n && r--){
        k = c;
        first = true;
        while(best < n && len[best] <= k){
            if(!first) printf(" ");
            first = false;
            printf("%s", V[best].c_str());
            k -= len[best];
            ++best;
        }   
        printf("\n");
    }
    return 0;
}