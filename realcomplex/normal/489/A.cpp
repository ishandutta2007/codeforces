#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main() {

    int n;
    cin >> n;
    int sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    int mz,ind;
    cout << n << "\n";
    for(int i = 0;i<n;i++){
        ind = i;
        mz = sk[i];
        for(int x = i+1;x<n;x++){
            if(sk[x] < mz){
                mz = sk[x];
                ind = x;
            }
        }
        cout << ind << " " << i << "\n";
        swap(sk[ind],sk[i]);
    }
	return 0;
}