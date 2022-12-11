#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main(){
    int n;
    cin >> n;
    int s[n];
    int mx = 0;
    int sum = 0;
    for(int i = 0;i<n;i++){
        cin >> s[i];
        if(s[i] > mx){
            mx = s[i];
        }
    }
    for(int y = 0;y<n;y++){
        sum += abs(s[y] - mx);
    }
    cout << sum;
    return 0;
}