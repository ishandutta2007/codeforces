#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> v){
    for(int i=0; i<v.size()-1; i++){
        if(abs(v[i]-v[i+1])>=2) return 1;
    }

    return 0;
}
vector<int> a;
vector<int> st;

int main(){
    int n, ma, pos;
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    while(!a.empty()){
        ma=0;
        if(check(a)){
            cout << "NO";
            return 0;
        }

        for(int i=0; i<a.size(); i++){
            if(a[i]>ma){
                ma=a[i];
                pos=i;
            }
        }

        st.push_back(a[pos]);
        a.erase(a.begin() + pos);
        if(check(st)){
            cout << "NO";
            return 0;
        }

    }

    cout << "YES";

}