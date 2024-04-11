function solve() {
    var n = readline()
    var s = readline().split(' ');
    
    var sz = 0;
    while (s[sz] === s[0]) sz++;

    if (s.length % sz) 
        return false;
    
    
    for(var i=0;i<s.length;i++) {
        var m = i % (2 * sz);
        if(m < sz) {
            if(s[i] != s[0]) return false;
        }
        else {
            if(s[i] == s[0]) return false;
        }
    }
    
    return true;
}

print(solve() ? "YES" : "NO");