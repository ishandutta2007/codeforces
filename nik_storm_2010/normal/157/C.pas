uses math;
var
  s,u,tmp : ansistring;
   answer,ds,du,i,t,tek,add : longint;



procedure kol(i:longint; var res:longint);
var j:longint;
 begin
  res:=0;
   for j:=1 to du do
    if s[i+j-1]<>u[j] then
   inc(res);
 end;


procedure koladd(i:longint; var res:longint);
var j,res1,res2:longint;
 begin
  res1:=0; res2:=0;
   for j:=1 to du do
    begin
     if i+j-1<=ds
      then
       begin
        if s[i+j-1]<>u[j] then inc(res1);
        inc(res2);
       end
      else
       begin
        if s[i+j-1]<>u[j] then inc(res2);
        inc(res1);
       end;
    end;
  res:=min(res1,res2);
 end;


begin

  readln(s);
   readln(u);
   ds:=length(s);
  du:=length(u);

  if ds>=du
   then
    begin
     add:=0;
    end
   else
    begin
     add:=abs(ds-du);
      tmp:=s;
       s:=u;
      u:=tmp;

      t:=ds;
       ds:=du;
      du:=t;
    end;

   answer:=maxlongint; s:=s+s;
    for i:=1 to ds do
     begin
      koladd(i,tek);
       if tek<answer then
      answer:=tek;
     end;
   answer:=answer+add;

  writeln(answer);

end.