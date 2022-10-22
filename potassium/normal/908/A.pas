program NYCCs;

var s         : string;
    cnt       : longint;
    i         : longint;

begin
     readln(s);

     for i := 1 to length(s) do
     begin
          if s[i] in ['a','e','i','o','u','1','3','5','7','9']
          then inc(cnt);
     end;

     writeln(cnt);
end.