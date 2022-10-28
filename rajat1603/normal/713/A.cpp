#include "bits/stdc++.h"
using namespace std;
int t;
char str[4];
long long val;
map < vector < int > , int > mp;
vector < int > convert(long long val){
    vector < int > ret;
    ret.clear();
    while(val){
        ret.emplace_back(val & 1);
        val /= 10;
    }
    while(ret.size() < 25){
        ret.emplace_back(0);
    }
    reverse(ret.begin() , ret.end());
    return ret;
}
int main(){
    scanf("%d" , &t);
    mp.clear();
    while(t--){
        scanf("%s" , str);
        scanf("%lld" , &val);
        if(str[0] == '+'){
            ++mp[convert(val)];
        }
        else if(str[0] == '-'){
            --mp[convert(val)];
        }
        else{
            string str = to_string(val);
            while(str.size() < 25){
                str = "0" + str;
            }
            vector < int > tmp;
            tmp.clear();
            for(char c : str){
                tmp.emplace_back(c - '0');
            }
            printf("%d\n" , mp[tmp]);
        }
    }
}