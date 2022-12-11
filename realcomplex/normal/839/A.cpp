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
    int given = 0;
    int l = 0;
    int c;
    int day = -1;
    for(int i = 0;i<n;i++){
        cin >> c;
        l+=c;
        given += min(l,8);
        l -= min(l,8);
        if(given>=k && day == -1){
            day = i+1;
        }
    }
    cout << day;
    return 0;
}