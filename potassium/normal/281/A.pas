program Capitalization;

var s                  : ansistring;

begin
     readln(s);

     if s[1] >= 'a'
     then s[1] := chr(ord(s[1]) XOR 32);

     writeln(s);
end.