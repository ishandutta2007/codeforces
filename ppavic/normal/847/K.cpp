#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair < string,string> pss;

const int N = 500;
map < pss , int > mp;
int n,a,b,f,k;
string lst;
string s1,s2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> k >> f;
    lst = "^";
    for(int i = 0;i<n;i++){
        cin >> s1 >> s2;
        if(s1 == lst){
            if(s1 < s2)
                mp[make_pair(s1,s2)] += b;
            else
                mp[make_pair(s2,s1)] += b;
        }
        else{
            if(s1 < s2)
                mp[make_pair(s1,s2)] += a;
            else
                mp[make_pair(s2,s1)] += a;
        }
        lst = s2;
    }
    int uz = 0;
    int sol = 0;
    vector < int > v;
    for(auto it = mp.rbegin();it != mp.rend();it++){
        v.push_back(it-> second);
    }
    sort(v.rbegin(),v.rend());
    for(int i = 0;i<v.size();i++){
        if(v[i] > f && i < k) sol += f;
        else sol += v[i];
    }
    cout << sol << endl;
}