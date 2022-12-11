#include<bits/stdc++.h>
using namespace std;
string a[3];
int s, p, m;
void sol(char ch){
    int p1, p2;
    p1 = p2 = -1;
    for(int i = 0; i <3 ;++i){
        if(a[i][1] == ch){
            if(p1 == -1) p1 = a[i][0] - '0';
            else p2 = a[i][0] - '0';
        }
    }
    if(p1 > p2) swap(p1, p2);
    if(p2 - p1 <= 2) cout<<1<<endl;
    else cout<<2<<endl;
}
int main()
{
    s = p = m = 0;
    for(int i = 0; i <3 ;++i) {
        cin>>a[i];
        if(a[i][1] == 's') s++;
        else if(a[i][1] == 'p') p++;
        else m++;
    }
    if(s == 3 || p == 3 || m == 3){
        sort(a, a+3);
        if(a[2][0] == a[1][0] && a[1][0] == a[0][0]){//same
            cout<<0<<endl;return 0;
        }
        else if(a[2][0] == a[1][0] || a[1][0] == a[0][0]){
            cout<<1<<endl;return 0;
        }
        if(a[2][0] - a[1][0] == 1 && a[1][0] - a[0][0] == 1){
            cout<<0<<endl;
        }
        else if(a[2][0] - a[1][0] <= 2 || a[1][0] - a[0][0] <= 2){
            cout<<1<<endl;
        }
        else cout<<2<<endl;
    }
    else if(s == 1 && p == 1 && m == 1){
        cout<<2<<endl;
    }
    else{
        if(s == 2) sol('s');
        else if( p == 2) sol('p');
        else sol('m');
    }
}