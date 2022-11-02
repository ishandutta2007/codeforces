var
    s:array[1..100] of string; a:array[65..90] of boolean;
     n,m,i,j:longint; tek,answer:int64;


begin

  readln(n,m);
  for i:=1 to n do readln(s[i]);

  answer:=1;
  for i:=1 to m do
    begin
      fillchar(a,sizeof(a),false); tek:=0;
      for j:=1 to n do
        if a[ord(s[j,i])]=false then
        begin
          a[ord(s[j,i])]:=true;
          inc(tek);
        end;
      answer:=(answer*tek) mod 1000000007;
    end;
  writeln(answer);

end.