#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long x[n + 1];
    for(int i = 2; i<=n; i+=2){
        cin >> x[i];
    }

    long long sum = 0;
    long long nw, cur;
    set<long long> sq;
    for(long long i = 1; i<5*(1e5); i++){
        sq.insert(i * i);
    }
    sq.insert(1e18);

    for(int i = 1; i<=n; i+=2){
        cur = sum;
        while(1){
            nw = *sq.upper_bound(sum);
            if(nw == 1e18){
                cout << "No";
                return 0;
            }

            if(sq.count(nw + x[i + 1])){
                x[i] = nw - cur;
                sum = nw + x[i + 1];
                break;
            }

            sum = nw;
        }
    }

    cout << "Yes" << endl;
    for(int i = 1; i<=n; i++){
        cout << x[i] << " ";
    }

}