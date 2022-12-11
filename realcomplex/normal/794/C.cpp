#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second
#define t abs

int main(){

    string a,b;
    cin >> a >> b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    int n = a.size();
    a = a.substr(0,(n/2) +(n%2));
    b = b.substr(0,(n/2));
    int t,t1;
    t = 0;
    t1 = 0;
    int g = 0;
    char rez[n];
    bool dod = false;
    for(int i = 0;i<n;i++){
        if(a[t] >= b[t1] && dod == false){
            t = a.size()-1;
            t1 = b.size()-1;
            g = n-1;
            dod = true;
        }
        if(i%2==0){

            rez[g] = a[t];
            if(dod == true){
                g--;
                t--;
            }
            else{
                g++;
                t++;
            }
        }
        else{
            rez[g] = b[t1];
            if(dod == true){
                g--;
                t1--;
            }
            else{
                g++;
                t1++;
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout << rez[i];
    }
    return 0;
}