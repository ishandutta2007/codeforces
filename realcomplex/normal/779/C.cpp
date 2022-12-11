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
    vector<pair<int,int> >sk(n);
    int s[n][2];
    for(int i = 0;i<2;i++){
        for(int x = 0;x<n;x++){
            cin >> s[x][i];
        }
    }
    for(int i = 0;i<n;i++){
        sk[i].fi = s[i][0] - s[i][1];
        sk[i].se = i;
    }
    sort(sk.begin(),sk.end());
    int sum = 0;
    for(int i = 0;i<n;i++){
        if(sk[i].fi < 0 || k > 0){
            sum += s[sk[i].se][0];
            k--;
        }
        else{
            sum +=s[sk[i].se][1] ;
        }
    }
    cout << sum;
    return 0;
}