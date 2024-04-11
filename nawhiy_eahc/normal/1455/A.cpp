#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        string s;
        cin >> s;
        printf("%d\n", (int)s.size());
    }
}