#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main()
{
    string a;
    cin >> a;
    string A1,A2;
    A1 = "BAAB";
    A2 = "ABBA";
    for(int i = 0;i<a.size();i++){
        if(A1.size() > 0){
            if(A1[0] == a[i] && A1[1] == a[i+1]){
                A1.erase(0,2);
                i++;
            }
        }
    }
    for(int i = 0;i<a.size();i++){
        if(A2.size() > 0){
            if(A2[0] == a[i] && A2[1] == a[i+1]){
                A2.erase(0,2);
                i++;
            }
        }
    }
    if(A1.size() == 0 || A2.size() == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}