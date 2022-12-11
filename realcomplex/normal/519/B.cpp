#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n;
    cin >> n;
    map<int,int>cr1,cr2,cr3;
    int sk[n];
    int sk1[n-1];
    int num;
    for(int j = 0;j<n;j++){
        cin >> sk[j];
        cr1[sk[j]]++;
    }
    for(int j = 0;j<n-1;j++){
        cin >> sk1[j];
        cr2[sk1[j]]++;
    }
    for(int j = 0;j<n-2;j++){
        cin >> num;
        cr3[num]++;
    }
    for(int j = 0;j<n;j++){
        if(cr1[sk[j]] != cr2[sk[j]]){
            cout << sk[j] << "\n";
            break;
        }
    }
    for(int j = 0;j<n-1;j++){
        if(cr3[sk1[j]] != cr2[sk1[j]]){
            cout << sk1[j] << "\n";
            break;
        }
    }
    return 0;
}