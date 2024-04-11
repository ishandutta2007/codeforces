#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
const int M = 1e3 + 3;
int n , m;
string lft[N];
string tmp;
string val1[N];
string op[N];
string val2[N];
map < string , int > mp;
int name1[N];
int name2[N];
int name3[N];
string mnans;
string mxans;
int arr1[N];
int arr2[N];
bool rekt[N];
char str[M];
void solve(int bit){
    int sum1 = 0;
    int sum2 = 0;
    arr1[0] = 0;
    arr2[0] = 1;
    for(int i = 1 ; i <= n ; ++i){
        if(rekt[i]){
            if(op[i] == "XOR"){
                arr1[i] = arr1[name2[i]] ^ arr1[name3[i]];
                arr2[i] = arr2[name2[i]] ^ arr2[name3[i]];
            }
            else if(op[i] == "AND"){
                arr1[i] = arr1[name2[i]] & arr1[name3[i]];
                arr2[i] = arr2[name2[i]] & arr2[name3[i]];
            }
            else{
                arr1[i] = arr1[name2[i]] | arr1[name3[i]];
                arr2[i] = arr2[name2[i]] | arr2[name3[i]];
            }
        }
        else{
            arr1[i] = val1[i][bit];
            arr2[i] = val1[i][bit];
        }
        sum1 += arr1[i];
        sum2 += arr2[i];
    }
    if(sum1 <= sum2){
        mnans += "0";
    }
    else{
        mnans += "1";
    }
    if(sum1 >= sum2){
        mxans += "0";
    }
    else{
        mxans += "1";
    }
}
int main(){
    cin >> n >> m;
    mp.clear();
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , str);
        lft[i] = str;
        mp[lft[i]] = i;
        name1[i] = i;
        scanf("%s" , str);
        scanf("%s" , str);
        val1[i] = str;
        if(!isdigit(val1[i][0])){
            scanf("%s" , str);
            op[i] = str;
            scanf("%s" , str);
            val2[i] = str;
            if(val1[i] == "?"){
                name2[i] = 0;
            }
            else{
                name2[i] = mp[val1[i]];
            }
            if(val2[i] == "?"){
                name3[i] = 0;
            }
            else{
                name3[i] = mp[val2[i]];
            }
            rekt[i] = 1;
        }
        else{
            rekt[i] = 0;
        }
    }
    mxans = "";
    mnans = "";
    for(int i = 0 ; i < m ; ++i){
        solve(i);
    }
    cout << mnans << "\n" << mxans << "\n";
}