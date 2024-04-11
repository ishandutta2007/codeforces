#include "bits/stdc++.h"
using namespace std;
int n;
int n1 , m1;
int n2 , m2;
int n3 , m3;
int ans1 , ans2 , ans3;
int main(){
    cin >> n;
    cin >> n1 >> m1;
    cin >> n2 >> m2;
    cin >> n3 >> m3;
    ans3 = n3;
    ans2 = n2;
    ans1 = (n - ans3 - ans2);
    if(ans1 > m1){
        int temp = ans1 - m1;
        ans1 = m1;
        ans2 += temp;
        if(ans2 > m2){
            temp = ans2 - m2;
            ans2 = m2;
            ans3 += temp;
        }
    }
    cout << ans1 << " " << ans2 << " " << ans3;
}