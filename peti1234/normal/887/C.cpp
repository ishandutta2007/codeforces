#include <bits/stdc++.h>

using namespace std;
int t[25];
int main()
{
    for (int i=1; i<=24; i++) {
        cin >> t[i];
    }
    if (t[1]==t[3] && t[1]==t[6] && t[1]==t[8] && t[5]==t[7] && t[5]==t[10] && t[5]==t[12] && t[9]==t[11] && t[9]==t[21] && t[9]==t[23] && t[2]==t[4] && t[22]==t[24] && t[2]==t[22] && t[13]==t[14] && t[13]==t[16] && t[13]==t[15] && t[17]==t[18] && t[17]==t[19] && t[17]==t[20]) {
        cout << "YES";
        return 0;
    }
    if (t[2]==t[4] && t[2]==t[5] && t[2]==t[7] && t[6]==t[8] && t[9]==t[6] && t[9]==t[11] && t[10]==t[12] && t[10]==t[22] && t[10]==t[24] && t[21]==t[23] && t[1]==t[21] && t[1]==t[3] && t[13]==t[14] && t[13]==t[16] && t[13]==t[15] && t[17]==t[18] && t[17]==t[19] && t[17]==t[20]) {
        cout << "YES";
        return 0;
    }
    if (t[1]==t[2] && t[1]==t[3] && t[1]==t[4] && t[9]==t[10] && t[11]==t[12] && t[10]==t[11] && t[14]==t[13] && t[13]==t[7] && t[7]==t[8] && t[5]==t[6] && t[19]==t[6] && t[5]==t[20] && t[17]==t[18] && t[23]==t[24] && t[18]==t[23] && t[21]==t[22] && t[15]==t[16] && t[21]==t[16] ) {
        cout << "YES";
        return 0;
    }
    if (t[1]==t[2] && t[1]==t[3] && t[1]==t[4] && t[9]==t[10] && t[11]==t[12] && t[10]==t[11] && t[15]==t[16] && t[15]==t[6] && t[5]==t[6] && t[7]==t[8] && t[17]==t[18] && t[17]==t[8] && t[19]==t[20] && t[19]==t[21] && t[19]==t[22] &&  t[13]==t[23] && t[13]==t[24] && t[14]==t[23] ) {
        cout << "YES";
        return 0;
    }
    if (t[5]==t[6] && t[5]==t[7] && t[5]==t[8] && t[21]==t[22] && t[21]==t[23] && t[21]==t[24] && t[2]==t[1] && t[2]==t[14] && t[2]==t[16] && t[13]==t[9] && t[9]==t[10] && t[13]==t[15] && t[11]==t[12] && t[12]==t[19] && t[12]==t[17] && t[18]==t[4] && t[20]==t[3] && t[3]==t[4] ) {
        cout << "YES";
        return 0;
    }
    if (t[5]==t[6] && t[5]==t[7] && t[5]==t[8] && t[21]==t[22] && t[21]==t[23] && t[21]==t[24] && t[1]==t[2] && t[1]==t[17] && t[1]==t[19] && t[18]==t[20] && t[10]==t[9] && t[18]==t[9] && t[11]==t[12] && t[11]==t[14] && t[11]==t[16] && t[13]==t[15] && t[4]==t[3] && t[13]==t[4]) {
        cout  << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}