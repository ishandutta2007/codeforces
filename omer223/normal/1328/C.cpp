#include <iostream>
#include <string>


using namespace std;

int main() {
    string a,b,x;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>x;
        a="";b="";
        int win =0;
        for(int i =0;i<n;i++){
            switch(x[i]){
                case '0':
                a.push_back('0');
                b.push_back('0');
                break;
                case '2':
                switch(win){
                    case 0:
                    a.push_back('1');
                    b.push_back('1');
                    break;
                    case 1:
                    b.push_back('2');
                    a.push_back('0');
                    break;
                    case 2:
                    b.push_back('0');
                    a.push_back('0');
                    break;
                }
                break;
                case '1':
                switch(win){
                    case 0:
                    a.push_back('1');
                    b.push_back('0');
                    win=1;
                    break;
                    case 1:
                    b.push_back('1');
                    a.push_back('0');
                    break;
                    case 2:
                    b.push_back('0');
                    a.push_back('1');
                    break;
                }
                break;
            }
        }
        cout<<a<<endl<<b<<endl;
    }
}