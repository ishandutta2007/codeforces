program storm;
var priz1,priz2,priz3,priz4,priz5,d,i,nom:longint;
    s:string;


procedure inputdata;
begin
 readln(s);
end;

procedure outputdata(priz:boolean);
begin
 if priz=true then writeln('YES')
              else writeln('NO');
end;

begin
 inputdata;
 priz1:=0; priz2:=0; priz3:=0; priz4:=0; priz5:=0;
 d:=length(s);
 for i:=1 to d do   if s[i]='h' then begin nom:=i+1; priz1:=1; break; end;
 for i:=nom to d do if s[i]='e' then begin nom:=i+1; priz2:=1; break; end;
 for i:=nom to d do if s[i]='l' then begin nom:=i+1; priz3:=1; break; end;
 for i:=nom to d do if s[i]='l' then begin nom:=i+1; priz4:=1; break; end;
 for i:=nom to d do if s[i]='o' then begin nom:=i+1; priz5:=1; break; end;

 if (priz1=1) and (priz2=1) and (priz3=1) and (priz4=1) and (priz5=1) then
    outputdata(true)                                                     else
    outputdata(false);
end.