program storm;
var sim:array[48..122] of longint;
    i,j:longint;
    d,kol:int64;
    s:ansistring;


procedure inputdata;
begin
 readln(s);
end;

procedure outputdata;
begin
 writeln(kol);
end;

begin
 inputdata; kol:=0; d:=length(s);
 for i:=1 to d do
  if sim[ord(s[i])]=0 then
    begin
    for j:=1 to d do
     if s[i]=s[j] then inc(sim[ord(s[i])]);
    inc(kol,sim[ord(s[i])]);
    end
                      else
    begin
    inc(kol,sim[ord(s[i])]);
    end;
 outputdata;
end.