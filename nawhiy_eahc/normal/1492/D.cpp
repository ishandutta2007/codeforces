#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int a, b, k; cin >> a >> b >> k;
    if(a == 0 && b == 1 && k == 0){
        cout << "Yes\n1\n1";
        return 0;
    }
    if(k >= a + b - 1){
        cout << "No";
        return 0;
    }
    if((a == 0 || b == 1)&& k > 0){
        cout << "No";
        return 0;
    }

    cout << "Yes\n";

    if(k <= a){
        for(int i=1;i<=b;i++) cout << "1";
        for(int i=1;i<=a;i++) cout << "0";
        cout << "\n";

        for(int i=1;i<b;i++) cout << "1";
        for(int i=1;i<=k;i++) cout << "0";
        cout << "1";
        for(int i=1;i<=a-k;i++) cout << "0";
    }
    
    else if(k < b){
        for(int i=1;i<=k+1;i++) cout << "1";
        cout << "0";
        for(int i=1;i<=b-k-1;i++) cout << "1";
        for(int i=1;i<=a-1;i++) cout << "0";
        cout << "\n";
        cout << "10";
        for(int i=1;i<=k;i++) cout << "1";
        for(int i=1;i<=b-k-1;i++) cout << "1";
        for(int i=1;i<=a-1;i++) cout << "0";
    }

    else{
        cout << "11";
        for(int i=1;i<=k-b+1;i++) cout << "0";
        for(int i=1;i<=b-2;i++) cout << "1";
        for(int i=1;i<=a-k+b-1;i++) cout << "0";
        cout << "\n";
        cout << "1";
        for(int i=1;i<=k-b+2;i++) cout << "0";
        for(int i=1;i<=b-1;i++) cout << "1";
        for(int i=1;i<=a-k+b-2;i++) cout << "0";
    }
}