#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,tmp;
        cin>>n;
        vector<int> a(32,0);
        for (int i = 0; i < n; i++){
            cin>>tmp;
            for (int j = 31; j >= 0; j--){
                if((tmp>>j)&1){
                    a[j]++;
                    break;
                }
            }
        }
        long long tot = 0;
        for (long long t : a){
            tot += (t * (t - 1)) / 2;
        }
        cout<<tot<<endl;
    }
}