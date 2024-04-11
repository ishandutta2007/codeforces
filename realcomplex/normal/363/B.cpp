#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main()
{
    int n,k;
    cin >> n >> k;
    int s[n];
    int sum = 0;
    for(int i = 0;i<n;i++){
        cin >> s[i];
        s[i] += sum;
        sum = s[i];
    }
    int mn = 1e9,index = 0;
    for(int x = 0;x<=n-k;x++){
        if(x == 0){
            mn = s[(x+k)-1];
            index = x+1;
        }
        else{
            if(mn >= s[(x+k)-1] - s[x-1]){
                index = x+1;
                mn = s[(x+k)-1] - s[x-1];
            }
        }
    }
    cout << index;
    return 0;
}