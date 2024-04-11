uses math;

var n,m         : int64;
    i,j         : longint;
    x,y         : longint;
    cnt,ans     : longint;
    a           : array[1..1000] of longint;
    s,s1,s2     : ansistring;

begin
     readln(s);

     ans := 0;

     for i := 0 to length(s) do
     begin
          cnt := 0;
          if i > 0
          then if s[i] = 'V'
               then s[i] := 'K'
               else s[i] := 'V';
          for j := 2 to length(s) do
              if (s[j] = 'K') AND (s[j-1] = 'V')
              then cnt := cnt + 1;
          ans := max(ans,cnt);
          if i > 0
          then if s[i] = 'V'
               then s[i] := 'K'
               else s[i] := 'V';
     end;

     writeln(ans);
end.