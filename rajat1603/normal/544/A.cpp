#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 101;
int k;
string str;
int cnt[26] = {0};
int distinct = 0;
bool used[26]={0};
int main(){
    cin >> k;
    cin >> str;
    for(string::iterator it = str.begin() ; it != str.end() ; ++it){
        cnt[*it - 'a']++;
        if( cnt[*it - 'a'] == 1){
            distinct ++;
        }
    }
    if(distinct < k){
        cout << "NO";
        return 0;
    }
    cout<<"YES";
    distinct = 0;
    for(string::iterator it = str.begin() ; it != str.end() ; ++it){
        if(!used[*it - 'a']){
            if(distinct < k){
                cout<<"\n";
            }
            used[*it- 'a'] = 1;
            distinct ++;
        }
        cout << *it;
    }
}