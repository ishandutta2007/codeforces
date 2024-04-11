#include<bits/stdc++.h>
#include <cmath> 
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
const int N = int(2e5) + 9;
ll getSubstring(ll len){
    return (len*(len+1))/2;
}
int main () {
    int n, k;
    char tmp;
    string s;
    vector<char>letters;
    cin>>n>>k>>s;
    for(int i = 0; i < k; i++){
        cin>>tmp; letters.push_back(tmp);
    }
    int start = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(find(letters.begin(), letters.end(), s[i]) != letters.end()){  }
        else{ sum+=getSubstring(i - start); start = i+1; }
    }
    sum+=getSubstring(n-start);
    cout<<sum;
}