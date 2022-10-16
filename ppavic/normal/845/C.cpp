#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef pair < int,int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int l,r,n,cur = 0;

vector < pii > v;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d%d",&l,&r);
        v.push_back(make_pair(l, -1));
        v.push_back(make_pair(r, 1));
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
        if(cur > 2){
            printf("NO\n");
            return 0;
        }
        cur -= v[i].second;
    }
    printf("YES\n");
}