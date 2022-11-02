uses math;
 var
     s,s1,s2:ansistring; i,d1,d2,ans,q:longint; a1,a2:boolean;


procedure prov(nom,leng:longint; var ans:boolean);
  var i,j,q,w:longint;
begin
  if nom=1 then
    begin
      if d1 mod leng <> 0 then begin ans:=false; exit; end else q:=d1 div leng;
      for j:=1 to q do
        begin
          w:=(j-1)*leng;
          for i:=1 to leng do
            if s1[w+i] <> s2[i] then
              begin
                ans:=false;
                exit;
              end;
        end;
      ans:=true;
    end
      else
    begin
      q:=d2 div leng;
      for j:=1 to q do
        begin
          w:=(j-1)*leng;
          for i:=1 to leng do
            if s2[w+i] <> s2[i] then
              begin
                ans:=false;
                exit;
              end;
        end;
      ans:=true;
    end;
end;


begin

  readln(s1); d1:=length(s1);
  readln(s2); d2:=length(s2);
  if d1<d2 then
    begin
      s:=s1; s1:=s2; s2:=s;
      q:=d1; d1:=d2; d2:=q;
    end;

  q:=round(sqrt(d2)); ans:=0;
  for i:=1 to q do
    begin
      if d2 mod i = 0 then
        begin
          prov(1,i,a1); prov(2,i,a2);
          if (a1=true) and (a2=true) then inc(ans);
          if (d2 div i) <> i then
            begin
              prov(1,d2 div i,a1); prov(2,d2 div i,a2);
              if (a1=true) and (a2=true) then inc(ans);
            end;
        end;
    end;
  writeln(ans);

end.