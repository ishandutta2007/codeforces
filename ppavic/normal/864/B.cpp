#include <iostream>
#include <set>

using namespace std;

set < char > st;
string s;
int n;

int main(){
    cin >> n >> s;
    int sol = 0;
    for(int i = 0;i<s.size();i++){
        st.clear();
        for(int j = i;j < s.size() && s[j] >= 'a' && s[j] <= 'z';j++){
            st.insert(s[j]);
        }
        if(st.size() > sol) sol = st.size();
    }
    cout << sol << endl;
}