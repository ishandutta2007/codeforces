#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair < int,int> pii;
typedef pair < double,double> pt;
typedef vector < int > vi;

const int N = 2e5 + 300;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

char s[N],s2[N];

int par[N],n;
vector < pair < char , char > > v;

int pr(int x){
    if(x == par[x]) return x;
    return par[x] = pr(par[x]);
}

void mrg(int x,int y){
    x =  pr(x),y = pr(y);
    par[x] = y;
}

int main(){
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%s",s2);
    for(int i = 0;i<50;i++) par[i] = i;
    for(int i = 0;i<n;i++){
        if(pr(s[i] - 'a') != pr(s2[i] - 'a')){
            v.push_back(make_pair(s[i],s2[i]));
            mrg(s[i] - 'a',s2[i] - 'a');
        }
    }
    printf("%d\n",v.size());
    for(int i = 0;i<v.size();i++){
        printf("%c %c\n",v[i].first,v[i].second);
    }
    return 0;
}