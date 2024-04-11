program Football;

var s1,s2        : string;
    i            : longint;

begin
     readln(s1);
     readln(s2);

     for i := 1 to length(s1) do
     begin
          if s1[i] < 'a'
          then s1[i] := char(ord(s1[i]) XOR 32);

          if s2[i] < 'a'
          then s2[i] := char(ord(s2[i]) XOR 32);

          if s1[i] > s2[i]
          then begin
                    writeln(1);
                    halt;
               end;

          if s1[i] < s2[i]
          then begin
                    writeln(-1);
                    halt;
               end;
     end;

     writeln(0);
end.