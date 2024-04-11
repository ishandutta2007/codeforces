program Football;

var s            : string;
    i            : longint;
    cnt          : longint;

begin
     readln(s);

     cnt := 1;

     for i := 2 to length(s) do
     begin
          if s[i] = s[i-1]
          then inc(cnt)
          else cnt := 1;

          if cnt >= 7
          then begin
                    writeln('YES');
                    halt;
               end;
     end;
     writeln('NO');
end.