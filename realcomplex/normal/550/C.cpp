#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

string its(int sk){
    string re;
    do{
        re = char((sk%10)+48) + re;
        sk/=10;
    }while(sk>0);
    return re;
}

int main()
{
    string k;
    cin >> k;
    int s = 0;
    bool c = false;
    string sub;
    int ans = 0;
    while(s<=1000){
        sub = its(s);
        for(int i = 0;i<k.size();i++){
            if(k[i] == sub[0]){
                sub.erase(0,1);
            }
        }
        if(sub.size() == 0){
            c = true;
            ans = s;
        }
        s+=8;
    }
    if(c == true){
        cout << "YES\n" << ans;
    }
    else{
        cout << "NO";
    }
    return 0;
}