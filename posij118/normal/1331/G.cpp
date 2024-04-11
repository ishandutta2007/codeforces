#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> p;
    int x;
    while(cin >> x){
        p.push_back(x);
    }

    reverse(p.begin(), p.end());
    for(int i = 0; i<p.size(); i++){
        long double result = p[i]*p[i]*p[i]*5 + sqrt(abs(p[i]));

        if(result > 400){
            cout << "f(" << p[i] << ") = MAGNA NIMIS!" << endl;
        }

        else{
             cout << fixed << setprecision(2) << "f(" << p[i] << ") = " << result << endl;
        }
    }
}