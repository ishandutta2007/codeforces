#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, k;
char T[100010];
int cnt[256];
LL r;

int main(){
    scanf("%d %d", &n, &k);
    scanf("%s", T);
    FWD(i,0,n)
        cnt[T[i]]++;
    sort(cnt+'A',cnt+'Z'+1);
    reverse(cnt+'A', cnt+'Z'+1);
    FWD(i,'A','Z'+1){
        r += (LL)min(cnt[i], k) * min(cnt[i], k);
        k -= min(cnt[i], k);
    }
    cout << r << endl;
    return 0;
}