#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define sf scanf
#define pf printf
int main()
{

    int n,k;
    cin >> n >> k;
    int sk;
    int a[n];
    vector<int>null;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        if(a[i] == 0){
            null.push_back(i);
        }
    }
    for(int i = 0;i<k;i++){
        cin >> sk;
        for(int x = 0;x<n;x++){
            if(a[x] == 0){
                a[x] = sk;
            }
        }
    }
    bool inc = false;
    for(int i = 1;i<n;i++){
        if(a[i] < a[i - 1]){
            inc = true;
            break;
        }
    }

    if(k < null.size() || (inc == false && null.size() <= 1)){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
    return 0;
}