#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

int main()
{
    int n,k;
    cin >> n >> k;
    pair<int,int>s[n];
    for(int i = 0;i<n;i++){
        cin >> s[i].fi;
        s[i].se = i;
    }
    sort(s,s+n);
    int c = 0;
    vector<int>ind;
    for(int i = 0;i<n;i++){
        if(k - s[i].fi >= 0 ){
            k-=s[i].fi;
            ind.push_back(s[i].se);
            c++;
        }
    }
    cout << c << "\n";
    for(int y = 0;y<ind.size();y++){
        cout << ind[y]+1 << " ";
    }
    return 0;
}