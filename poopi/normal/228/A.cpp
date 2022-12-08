                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <set>
using namespace std;

#define int64 long long
#define P pair<int, int>

int n, cnt;
set <int> st;
int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    for(int i = 0; i < 4; i++){
        cin >> n;
        st.insert(n);
    }
    cout << 4 - st.size() << endl;
    return 0;
}