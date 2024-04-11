#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define inf (1 << 14)
#define sz(x) (int)x.size()
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
#define MAX 300001

int arr[26] = {0};
int main(){
    string s;
    cin >> s;
    const string cmp = s;
    int len = s.length();
    for(auto i:s){
        arr[i-'a']++;
    }
    for(int i=0;i<26;i++){
        if(arr[i] >= len-1){
            cout << "Impossible";
            return 0;
        }
    }
    if(len%2){
        cout << 2;
    }else{
        if(!equal(s.begin(), s.begin()+len/2, s.begin()+len/2)){
            cout << 1;
        }else{
            int repeat = 0;
            for(int i=0;i<len-1;i++){
                char c = s.front();
                s.erase(s.begin());
                s.push_back(c);
                if(s == cmp){
                    repeat = i + 1;
                    break;
                }
            }
            if(repeat % 2){
                cout << 2;
            }else{
                cout << 1;
            }
        }
    }
    return 0;
}