#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n , m;
string str1;
string str2;
int curcnt = 0;
char curchar = '$';
int ans = 0;
char fchar;
int fcnt;
char lchar;
int lcnt;
/*
Z algo Copied from Geeks for geeks
*/
//  Fills Z array for given string str[]
void getZarr(string str, int Z[])
{
    int n = str.length();
    int L, R, k;
 
    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        // if i>R nothing matches so we will calculate.
        // Z[i] using naive way.
        if (i > R)
        {
            L = R = i;
 
            // R-L = 0 in starting, so it will start
            // checking from 0'th index. For example,
            // for "ababab" and i = 1, the value of R
            // remains 0 and Z[i] becomes 0. For string
            // "aaaaaa" and i = 1, Z[i] and R become 5
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i-L;
 
            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R-i+1)
                 Z[i] = Z[k];
 
            // For example str = "aaaaaa" and i = 2, R is 5,
            // L is 0
            else
            {
                //  else start from R  and check manually
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}
void search(string text, string pattern)
{
    // Create concatenated string "P$T"
    string concat = pattern + "$" + text;
    int l = concat.length();
 
    // Construct Z array
    int Z[l];
    getZarr(concat, Z);
    
    //  now looping through Z array for matching condition
    char llchar = '$';
    int llnum = 0;
    int cur = 0;
    for(int i = 0 ; i < 100 ; ++i)
        concat += '$';

    for (int i = 0; i < l; ++i)
    {
        // if Z[i] (matched region) is equal to pattern
        // length  we got the pattern
        if(isalpha(concat[i]) || concat[i] == '$'){
            llchar = concat[i];
            llnum = cur;
            cur = 0;
        }
        else{
            cur *= 10;
            cur += concat[i] - '0';
        }
        if(Z[i] == pattern.length()){
            if(llchar != fchar){
                continue;
            }
            if(llnum < fcnt){
                continue;
            }
            int lllol = i + Z[i];
            int num = 0;
            while(isdigit(concat[lllol]) && lllol < l){
                num *= 10;
                num += concat[lllol] - '0';
                lllol++;
            }
            char tmp = concat[lllol];
            if(tmp != lchar){
                continue;
            }
            if(num < lcnt){
                continue;
            }
            ++ans;
        }
    }
}
vector < pair < char , int > > arr1;
vector < pair < char , int > > arr2;
void brute(){
    if(arr2.size() == 1){
        for(auto it : arr1){
            if(it.first == arr2[0].first){
                ans += max(0LL , it.second - arr2[0].second + 1);
            }
        }
    }
    else{
        char lst = '$';
        int cnt = 0;
        for(auto it : arr1){
            if(lst == arr2[0].first && it.first == arr2[1].first){
                ans += (cnt >= arr2[0].second) && (it.second >= arr2[1].second);
            }
            lst = it.first;
            cnt = it.second;
        }
    }
    cout << ans;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        int tmp;
        char x1;
        char x2;
        cin >> tmp >> x1 >> x2;
        if(x2 == curchar){
            curcnt += tmp;
        }
        else{
            if(curchar != '$'){
                str1 += to_string(curcnt);
                str1 += curchar;
                arr1.emplace_back(make_pair(curchar , curcnt));
            }
            curchar = x2;
            curcnt = tmp;
        }
    }
    str1 += to_string(curcnt);
    str1 += curchar;
    arr1.emplace_back(make_pair(curchar , curcnt));
    curcnt = 0;
    curchar = '$';
    bool ok = 0;
    for(int i = 1 ; i <= m ; ++i){
        int tmp;
        char x1;
        char x2;
        cin >> tmp >> x1 >> x2;
        if(x2 == curchar){
            curcnt += tmp;
        }
        else{
            if(curchar != '$'){
                if(ok){
                    str2 += to_string(curcnt);
                    str2 += curchar;
                }
                else{
                    ok = 1;
                    fchar = curchar;
                    fcnt = curcnt;
                }
                arr2.emplace_back(make_pair(curchar , curcnt));
            }
            curchar = x2;
            curcnt = tmp;
        }
    }
    if(ok){
        str2 += to_string(curcnt);
        str2 += curchar;
        lchar = curchar;
        lcnt = curcnt;
    }
    else{
        ok = 1;
        fchar = curchar;
        fcnt = curcnt;
    }
    arr2.emplace_back(make_pair(curchar , curcnt));
    if(arr2.size() <= 2){
        brute();
        return 0;
    }
    str2.pop_back();
    while(isdigit(str2.back())){
        str2.pop_back();
    }
    search(str1 , str2);
    cout << ans;
}