#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int convert(string str){
    if(str == "S"){
        return 1;
    }
    if(str == "M"){
        return 2;
    }
    if(str == "L"){
        return 3;
    }
    if(str == "XL"){
        return 4;
    }
    if(str == "XXL"){
        return 5;
    }
    return 6;
}
string convert2(int idx){
    if(idx == 1){
        return "S";
    }
    if(idx == 2){
        return "M";
    }
    if(idx == 3){
        return "L";
    }
    if(idx == 4){
        return "XL";
    }
    if(idx == 5){
        return "XXL";
    }
    return "XXXL";
}
int n;
string str;
pair < int , int > arr[N];
int cnt[7];
int ans[N];
void rekt(){
    cout << "NO\n";
    exit(0);
}
int main(){
    for(int i = 1 ; i <= 6 ; ++i){
        cin >> cnt[i];
    }
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> str;
        string cur = "";
        arr[i].second = 0;
        for(char c : str){
            if(c == ','){
                arr[i].second = convert(cur);
                cur = "";
            }
            else{
                cur += c;
            }
        }
        arr[i].first = convert(cur);
    }
    for(int i = 1 ; i <= 6 ; ++i){
        for(int k = 1 ; k <= 6 ; ++k){
            for(int j = 1 ; j <= n ; ++j){
                if(!ans[j]){
                    if(cnt[arr[j].first] == 0 && cnt[arr[j].second] == 0){
                        rekt();
                    }
                    else if(cnt[arr[j].first] == 0){
                        --cnt[arr[j].second];
                        ans[j] = arr[j].second;
                    }
                    else if(cnt[arr[j].second] == 0){
                        --cnt[arr[j].first];
                        ans[j] = arr[j].first; 
                    }
                }
            }
        }
        for(int j = 1 ; j <= n ; ++j){
            if(!ans[j]){
                if(arr[j].first == i && cnt[i]){
                    --cnt[i];
                    ans[j] = i;
                }
                if(arr[j].second == i && cnt[i]){
                    --cnt[i];
                    ans[j] = i;
                }
            }
        }
    }
    cout << "YES\n";
    for(int i = 1 ; i <= n ; ++i){
        cout << convert2(ans[i]) << "\n";
    }
}