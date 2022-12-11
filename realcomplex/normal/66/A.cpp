#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool compN(string a,string b){
    if(a.size() > b.size()){
        return true;
    }
    else if(b.size() > a.size()){
        return false;
    }
    else{
        for(int i = 0;i<a.size();i++){
            if(a[i] > b[i]){
                return true;
            }
            else if(b[i] > a[i]){
                return false;
            }
        }
        return false;
    }
}

int main()
{
    string k;
    cin >> k;
    if(compN("128",k) == true){
        cout << "byte";
    }
    else if(compN("32768",k) == true){
        cout << "short";
    }
    else if(compN("2147483648",k) == true){
        cout << "int";
    }
    else if(compN("9223372036854775808",k) == true){
        cout << "long";
    }
    else{
        cout << "BigInteger";
    }
    return 0;
}