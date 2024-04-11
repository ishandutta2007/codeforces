uses math;

var n,i      : longint;
    cnt,ans  : longint;
    a        : array[1..1000] of longint;

    s        : ansistring;
    b        : boolean;

begin
     readln(s);

     b := TRUE;

     for i := 2 to length(s) do
         if s[i] >= 'a'
         then b := FALSE;

     if b
     then for i := 1 to length(s) do
              s[i] := chr(ord(s[i]) XOR 32);

     writeln(s);
end.