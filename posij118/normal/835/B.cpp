#include <bits/stdc++.h>
using namespace std;

int cislo(char c){
    if(c=='0') return 0;
    else if(c=='1') return 1;
    else if(c=='2') return 2;
    else if(c=='3') return 3;
    else if(c=='4') return 4;
    else if(c=='5') return 5;
    else if(c=='6') return 6;
    else if(c=='7') return 7;
    else if(c=='8') return 8;
    else if(c=='9') return 9;
}

int main(){
    int k, sum, x;
    sum=0;
    x=0;
    string s;
    cin >> k >> s;

    int cnt[10];
    fill(cnt, cnt + 10, 0);

    for(int i=0; i<s.size(); i++){
        cnt[cislo(s[i])]++;
        sum+=cislo(s[i]);
    }

    for(int i=0; i<10; i++){
        while(cnt[i]>0){
            if(sum>=k){
                cout << x;
                return 0;
            }
            cnt[i]--;
            sum+=(9-i);
            x++;

        }
    }

    if(sum>=k){
        cout << x;
        return 0;
    }

}