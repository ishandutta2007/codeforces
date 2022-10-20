#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int getpi(string &p){
    int m=(int)p.size(), j=0;
    vector<int> pi(m, 0);
    for (int i=1;i<m;i++){
        while(j>0 && p[i]!=p[j]) j=pi[j-1];
        if (p[i]==p[j]) pi[i]= ++j;
    }
    return pi.back();
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int i=0, j=(int)str.size()-1;
        while(i<=j){
            if (str[i]==str[j]){
                i++, j--;
            }
            else break;
        }
        if (i>j){
            cout << str << '\n';
            continue;
        }
        string str2, str3;
        for (int k=i;k<=j;k++) str2.push_back(str[k]);
        str2.push_back('#');
        for (int k=j;k>=i;k--){
            str2.push_back(str[k]);
            str3.push_back(str[k]);
        }
        str3.push_back('#');
        for (int k=i;k<=j;k++) str3.push_back(str[k]);
        int tmp2=getpi(str2), tmp3=getpi(str3);
        if (tmp2>tmp3){
            for (int k=0;k<i+tmp2;k++) cout << str[k];
            for (int k=j+1;k<(int)str.size();k++) cout << str[k];
            cout << '\n';
        }
        else{
            for (int k=0;k<i;k++) cout << str[k];
            for (int k=j+1-tmp3;k<(int)str.size();k++) cout << str[k];
            cout << '\n';
        }
    }
    return 0;
}