program NextRound;

var s   : string;
    i   : longint;

begin
     readln(s);

     for i := 1 to length(s) do
     begin
          if s[i] < 'a'
          then s[i] := char(ord(s[i]) XOR 32);

          if NOT(s[i] in ['a','e','i','o','u','y'])
          then write('.',s[i]);
     end;

     readln;
end.