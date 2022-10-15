#include <bits/stdc++.h>
using namespace std;
const long MX = 10000000;
long cnt[MX+10], f[MX+10];
bool prime[MX+10];
 
void sieve()
{
    int i, j;
    for(i = 2; i <= MX; i ++){
        if(prime[i] == 0){
            f[i] = cnt[i];
            for(j = i+i; j <= MX; j += i){
                prime[j] = 1;
                f[i] += cnt[j];
            }
        }
    }
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
    for(int i=0; i<n; i++) {
        long y;
        cin >> y;
        cnt[y]++;
    }
    sieve();
 
    for(int i=2; i<=MX; i++) f[i] += f[i-1];
    int q;
    cin >> q;
    while(q--) {
        long l, r;
        cin>>l>>r;
        l=min(l, MX);
        r=min(r, MX);
        cout<<f[r]-f[l-1]<<endl;
    }
}