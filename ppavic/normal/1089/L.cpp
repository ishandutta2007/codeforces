#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 500;

vector < int > v[N];
vector < int > all;

int a[N], b[N], n, k, k2;

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0;i<n;i++)
        scanf("%d", a + i);
    for(int i = 0;i<n;i++)
        scanf("%d", b + i);
    for(int i = 0;i<n;i++){
        v[a[i]].push_back(b[i]);
    }
    for(int i = 1;i<=k;i++){
        sort(v[i].rbegin(), v[i].rend());
        if(v[i].size() == 0) continue;
        k2--;
        for(int j = 1;j<v[i].size();j++)
            all.push_back(v[i][j]);
    }
    k2 += k;
    sort(all.begin(), all.end());
    ll sol = 0;
    for(int i = 0;i<k2;i++)
        sol += (ll)all[i];
    printf("%lld\n",sol);
}